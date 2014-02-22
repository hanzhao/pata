#TLE
ans = 0
s = gets.chomp.split(//)
s2 = s.reverse
f = Array.new(s.size) { Array.new }
s.each_with_index do |a, i|
  s2.each_with_index do |b, j|
    if a == b
      if i == 0 || j == 0 || f[i - 1][j - 1] == nil
        f[i][j] = 1
      else
        f[i][j] = f[i - 1][j - 1] + 1
      end
      ans = f[i][j] > ans ? f[i][j] : ans
    end
  end
end
puts ans
