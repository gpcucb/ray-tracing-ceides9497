class Rgb
  attr_accessor :r, :g, :b

  def initialize(r,g,b)
    @r = fix(r.to_f)
    @g = fix(g.to_f)
    @b = fix(b.to_f)
  end

  def fix(num)
    if num<0
      num=0
    end
    if num>1
      num=1
    end
    return num
  end

  def plus_color (a_color)
    Rgb.new(@r+a_color.r, @g+a_color.g, @b+a_color.b)
  end

  def minus_color (a_color)
    Rgb.new(@r-a_color.r, @g-a_color.g, @b-a_color.b)
  end

  def multiply_color (a_color)
    red = @r*a_color.r
    green = @g*a_color.g
    blue = @b*a_color.b

    Rgb.new(red,green,blue)
  end

  def scalar_color (a_number)
    number_as_float = a_number.to_f
    Rgb.new(@r*number_as_float, @g*number_as_float, @b*number_as_float)
  end

end
