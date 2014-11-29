#!/usr/bin/env ruby
class Rational
  def to_s
    t = self
    t = -t if t < 0
    if self < 0
      "(-#{t})"
    elsif t.truncate == 0
      t == 0 ? "0" : "#{t.numerator}/#{t.denominator}"
    else
      t -= t.truncate
      t == 0 ? "#{self.truncate}" : "#{self.truncate} #{t.numerator}/#{t.denominator}"
    end
  end
end
a, b = gets.split.map { |x| Rational(x) }
puts "#{a} + #{b} = #{a + b}"
puts "#{a} - #{b} = #{a - b}"
puts "#{a} * #{b} = #{a * b}"
print "#{a} / #{b} = "
begin
  puts a / b
rescue ZeroDivisionError
  puts "Inf"
end
