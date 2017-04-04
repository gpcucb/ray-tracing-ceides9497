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
    e= Vector.new(0,50,-200)
    center= Vector.new(0,50,-100)
    up= Vector.new(0,1,0)
    fov= 39.31
    df=0.035
    @camera = Camera.new(e, center, up, fov, df)

    #colors
    mediumBlue = Rgb.new(0.196078,0.196078,0.8)
    fucsia = Rgb.new(1.0, 0.0, 1.0)
    orange = Rgb.new(1, 0.5,0.0)
    pink = Rgb.new(0.737255 , 0.560784 , 0.560784)
    skyBlue = Rgb.new(0.196078,0.6,0.8)
    silver = Rgb.new(0.90,0.91,0.98)
    yellow = Rgb.new(1.0, 1.0, 0)
    seaGreen = Rgb.new(0.137255,0.556863,0.419608)
    white = Rgb.new(1,1,1)
    aquamarine = Rgb.new(0.439216,0.858824,0.576471)
    gold = Rgb.new(0.8,0.498039,0.196078)

    # Light Values
    light_color = white
    light_position = Vector.new(-150, 200.0, 50.0)
    @light = Light.new(light_position,light_color)

    # Sphere values
    position = Vector.new(0,50,280)
    radius = 25
    sphere_diffuse = fucsia
    sphere_specular =Rgb.new(1.0,1.0,1.0)
    sphere_reflection = 0.5
    sphere_power = 60
    sphere_material = Material.new(sphere_diffuse, sphere_reflection, sphere_specular, sphere_power)

    position2 = Vector.new(50,25,280)
    radius2 = 25
    sphere_diffuse2 = seaGreen
    sphere_specular2 =Rgb.new(1.0,1.0,1.0)
    sphere_reflection2 = 0.5
    sphere_power2 = 60
    sphere_material2 = Material.new(sphere_diffuse2, sphere_reflection2, sphere_specular2, sphere_power2)

    position3 = Vector.new(-50,25,280)
    radius3 = 25
    sphere_diffuse3 = yellow
    sphere_specular3 =Rgb.new(1.0,1.0,1.0)
    sphere_reflection3 = 0.5
    sphere_power3 = 60
    sphere_material3 = Material.new(sphere_diffuse3, sphere_reflection3, sphere_specular3, sphere_power3)

    # Triangle values - walls
    a = Vector.new(220,0,325)
    b = Vector.new(0,0,325)
    c = Vector.new(220,150,310)
    triangle_diffuse = silver
    triangle_specular = Rgb.new(1.0,1.0,1.0)
    triangle_reflection = 0.5
    triangle_power = 60
    triangle_material = Material.new(triangle_diffuse, triangle_reflection, triangle_specular, triangle_power)

    a2 = Vector.new(0,150,325)
    b2 = Vector.new(220,150,310)
    c2 = Vector.new(0,0,325)
    triangle_diffuse2 = silver
    triangle_specular2 = Rgb.new(1.0,1.0,1.0)
    triangle_reflection2 = 0.5
    triangle_power2 = 60
    triangle_material2 = Material.new(triangle_diffuse2, triangle_reflection2, triangle_specular2, triangle_power2)

    aw = Vector.new(0,0,325)
    bw = Vector.new(-220,0,325)
    cw = Vector.new(-220,150,310)
    triangle_diffusew = silver
    triangle_specularw = Rgb.new(1.0,1.0,1.0)
    triangle_reflectionw = 0.5
    triangle_powerw = 60
    triangle_materialw = Material.new(triangle_diffusew, triangle_reflectionw, triangle_specularw, triangle_powerw)

    aw1 = Vector.new(-220,150,310)
    bw1 = Vector.new(0,150,325)
    cw1 = Vector.new(0,0,325)
    triangle_diffusew1 = silver
    triangle_specularw1 = Rgb.new(1.0,1.0,1.0)
    triangle_reflectionw1 = 0.5
    triangle_powerw1 = 60
    triangle_materialw1 = Material.new(triangle_diffusew1, triangle_reflectionw1, triangle_specularw1, triangle_powerw1)

    #piso
    ap = Vector.new(220,0,325)
    bp = Vector.new(100,0,160)
    cp = Vector.new(-220,0,325)
    triangle_diffusep = white
    triangle_specularp = Rgb.new(1.0,1.0,1.0)
    triangle_reflectionp = 0.5
    triangle_powerp = 60
    triangle_materialp = Material.new(triangle_diffusep, triangle_reflectionp, triangle_specularp, triangle_powerp)

    ap1 = Vector.new(-220,0,325)
    bp1 = Vector.new(100,0,160)
    cp1 = Vector.new(-100,0,160)
    triangle_diffusep1 = white
    triangle_specularp1 = Rgb.new(1.0,1.0,1.0)
    triangle_reflectionp1 = 0.5
    triangle_powerp1 = 60
    triangle_materialp1 = Material.new(triangle_diffusep1, triangle_reflectionp1, triangle_specularp1, triangle_powerp1)

    #estandarte
    aEst = Vector.new(0,25,280)
    bEst = Vector.new(0,0,255)
    cEst = Vector.new(-25,0,300)
    triangle_diffuseEst = gold
    triangle_specularEst = Rgb.new(1.0,1.0,1.0)
    triangle_reflectionEst = 0.5
    triangle_powerEst = 60
    triangle_materialEst = Material.new(triangle_diffuseEst, triangle_reflectionEst, triangle_specularEst, triangle_powerEst)

    aEst1 = Vector.new(25,0,300)
    bEst1 = Vector.new(0,0,255)
    cEst1 = Vector.new(0,25,280)
    triangle_diffuseEst1 = gold
    triangle_specularEst1 = Rgb.new(1.0,1.0,1.0)
    triangle_reflectionEst1 = 0.5
    triangle_powerEst1 = 60
    triangle_materialEst1 = Material.new(triangle_diffuseEst1, triangle_reflectionEst1, triangle_specularEst1, triangle_powerEst1)


    #llenando
    @sphere = Sphere.new(position, radius, sphere_material)
    @sphere2 = Sphere.new(position2, radius2, sphere_material2)
    @sphere3 = Sphere.new(position3, radius3, sphere_material3)
    @triangle = Triangle.new(a, b, c, triangle_material)
    @triangle2 = Triangle.new(a2, b2, c2, triangle_material2)
    @trianglew = Triangle.new(aw, bw, cw, triangle_materialw)
    @trianglew1 = Triangle.new(aw1, bw1, cw1, triangle_materialw1)
    @trianglep = Triangle.new(ap, bp, cp, triangle_materialp)
    @trianglep1 = Triangle.new(ap1, bp1, cp1, triangle_materialp1)
    @estandarte = Triangle.new(aEst, bEst, cEst, triangle_materialEst)
    @estandarte1 = Triangle.new(aEst1, bEst1, cEst1, triangle_materialEst1)
    @objects=[]
    @objects << @trianglep1 << @trianglep << @trianglew1 << @trianglew << @triangle2 << @triangle << @estandarte << @estandarte1 << @sphere << @sphere2 << @sphere3
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

  def blinnPhongShading(intersectionPoint, intersectionNormal, ray, light, object)
    n = intersectionNormal.normalize
    v = ray.position.minus(intersectionPoint).normalize
    l = light.position.minus(intersectionPoint).normalize
    h = v.plus(l).normalize
    nh = n.scalar_product(h)
    ks = object.material.specular
    power = object.material.power
    ksI = ks.multiply_color(light.color)
    max = max(0,nh)

    return ksI.scalar_color(max**power)
  end

  def ambientShading(object)
    @ambientLight = Rgb.new(0.003,0.003,0.003)
    ka = object.material.diffuse
    return @ambientLight.multiply_color(ka)
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
      blinnPhong = blinnPhongShading(intersectionPoint, intersectionNormal, ray, @light, @obj_int)
      ambientShadow = ambientShading(@obj_int)
      puts "lambert r:#{lamberShadow.r} g:#{lamberShadow.g} b:#{lamberShadow.b}"
      puts "blinnPhong r:#{blinnPhong.r} g:#{blinnPhong.g} b:#{blinnPhong.b}"
      puts "ambientShadow r:#{ambientShadow.r} g:#{ambientShadow.g} b:#{ambientShadow.b}"
      #color = lamberShadow
      color = blinnPhong.plus_color(lamberShadow).plus_color(ambientShadow)
    end

    return {red: color.r, green: color.g, blue: color.b}
  end
end
