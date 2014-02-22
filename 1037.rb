# TLE
n = gets.chomp.to_i
a = gets.chomp.split(' ').map &:to_i
m = gets.chomp.to_i
b = gets.chomp.split(' ').map &:to_i
a.sort!; b.sort!
ans = 0
a.each_index do |i|
  if i < b.size && a[i] < 0 && b[i] < 0
    ans += a[i] * b[i]
  else
    break
  end
end
a.reverse!; b.reverse!
a.each_index do |i|
  if i < b.size && a[i] > 0 && b[i] > 0
    ans += a[i] * b[i]
  else
    break
  end
end
puts ans
