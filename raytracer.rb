require_relative 'renderer.rb'
require_relative 'camera.rb'
require_relative 'vector.rb'
require_relative 'rgb.rb'
require_relative 'intersection.rb'
require_relative 'sphere.rb'
require_relative 'triangle.rb'
require_relative 'light.rb'
require_relative 'material.rb'

class RayTracer < Renderer

  attr_accessor :camera

  def initialize(width, height)
    super(width, height, 250.0, 250.0, 250.0)

    @nx = @width
    @ny = @height
    # Camera values
    e= Vector.new(0,0,-200)
    center= Vector.new(0,0,-100)
    up= Vector.new(0,1,0)
    fov= 39.31
    df=0.035
    @camera = Camera.new(e, center, up, fov, df)

    # Light Values
    light_color = Rgb.new(1,1,1)
    light_position = Vector.new(-50, 100.0, 50.0)
    @light = Light.new(light_position,light_color)

    # Sphere values
    position = Vector.new(0,60,300)
    radius = 50
    sphere_diffuse = Rgb.new(1.0, 0.0, 1.0)
    sphere_specular =Rgb.new(1.0,1.0,1.0)
    sphere_reflection = 0.5
    sphere_power = 60
    sphere_material = Material.new(sphere_diffuse, sphere_reflection, sphere_specular, sphere_power)

    # Triangle values
    a = Vector.new(220,0,360)
    b = Vector.new(-220,0,360)
    c = Vector.new(220,100,360)
    triangle_diffuse = Rgb.new(1.0, 1.0, 0)
    triangle_specular = Rgb.new(1.0,1.0,1.0)
    triangle_reflection = 0.5
    triangle_power = 60
    triangle_material = Material.new(triangle_diffuse, triangle_reflection, triangle_specular, triangle_power)

    a2 = Vector.new(-220,100,360)
    b2 = Vector.new(220,100,360)
    c2 = Vector.new(-220,0,360)
    triangle_diffuse2 = Rgb.new(1.0, 1.0, 0)
    triangle_specular2 = Rgb.new(1.0,1.0,1.0)
    triangle_reflection2 = 0.5
    triangle_power2 = 60
    triangle_material2 = Material.new(triangle_diffuse2, triangle_reflection2, triangle_specular2, triangle_power2)

    a3 = Vector.new(220,0,360)
    b3 = Vector.new(100,-25,160)
    c3 = Vector.new(-220,0,360)
    triangle_diffuse3 = Rgb.new(0.917647, 0.678431, 0.917647)
    triangle_specular3 = Rgb.new(1.0,1.0,1.0)
    triangle_reflection3 = 0.5
    triangle_power3 = 60
    triangle_material3 = Material.new(triangle_diffuse3, triangle_reflection3, triangle_specular3, triangle_power3)

    a4 = Vector.new(-220,0,360)
    b4 = Vector.new(100,-25,160)
    c4 = Vector.new(-100,-25,160)
    triangle_diffuse4 = Rgb.new(0.917647, 0.678431, 0.917647)
    triangle_specular4 = Rgb.new(1.0,1.0,1.0)
    triangle_reflection4 = 0.5
    triangle_power4 = 60
    triangle_material4 = Material.new(triangle_diffuse4, triangle_reflection4, triangle_specular4, triangle_power4)

    @sphere = Sphere.new(position, radius, sphere_material)
    @triangle = Triangle.new(a, b, c, triangle_material)
    @triangle2 = Triangle.new(a2, b2, c2, triangle_material2)
    @triangle3 = Triangle.new(a3, b3, c3, triangle_material3)
    @triangle4 = Triangle.new(a4, b4, c4, triangle_material4)
    @objects=[]
    @objects << @triangle4 << @triangle3 << @triangle2 << @triangle << @sphere
  end

  def max(number1,number2)
    if number1 > number2
      return number1
    else
      return number2
    end
  end

  def lamberthianShading(intersectionPoint, intersectionNormal, ray, light, object)
    n = intersectionNormal.normalize
    l = light.position.minus(intersectionPoint).normalize
    nl = n.scalar_product(l)
    max = max(0,nl)
    kd = object.material.diffuse
    kdI = kd.multiply_color(light.color)
    return kdI.scalar_color(max)
  end



  def calculate_pixel(i, j)
    e = @camera.e
    dir = @camera.ray_direction(i,j,@nx,@ny)
    ray = Ray.new(e, dir)
    t = Float::INFINITY

    @obj_int = nil#intersected object
    @objects.each do |obj|
      intersection = obj.intersection?(ray, t)
      if intersection.successful?
        @obj_int = obj
        t = intersection.t
      end
    end
    if @obj_int==nil
      color = Rgb.new(0,0,0)
    else
      #color = @obj_int.material.diffuse #2D
      intersectionPoint = ray.position.plus(ray.direction.num_product(t))
      intersectionNormal = @obj_int.normal(intersectionPoint)
      lamberShadow = lamberthianShading(intersectionPoint, intersectionNormal, ray, @light, @obj_int)
      puts "lambert r:#{lamberShadow.r} g:#{lamberShadow.g} b:#{lamberShadow.b}"
      color = lamberShadow
    end

    return {red: color.r, green: color.g, blue: color.b}
  end
end
