#!/usr/bin/env ruby
C = ['ling', 'yi', 'er', 'san', 'si', 'wu', 'liu', 'qi', 'ba', 'jiu']
N = [nil, 'Shi', 'Bai', 'Qian']
class Integer
  def to_chinese
    if self == 0
      return 'ling'
    end
    x = self
    (print 'Fu '; x = -x) if x < 0
    ans = []
    num = x.to_s.split(//).map &:to_i
    e = num.size - 9
    w = num.size - 5
    n = 0
    t = num.size - 1
    flag, flag2 = false, false
    num.reverse.each do |x|
      (ans << 'Yi'; flag = false) if t == e
      (ans << 'Wan'; flag = false) if t == w
      (ans << N[n]; flag = true) if n != 0 && x != 0
      (ans << C[x]; flag = true) if (flag || x != 0) && (ans.size == 0 || ans.last != 'ling')
      n += 1
      n = 0 if n == 4
      t -= 1
    end
    ans.reverse.join(' ')
  end
end
puts gets.to_i.to_chinese
