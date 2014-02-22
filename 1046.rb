# TLE
def min(a, b)
  a < b ? a : b
end
s = [0, 0]
l = gets.chomp.split(' ').map &:to_i
1.upto(l[0]) { |i| s[i + 1] = s[i] + l[i] }
sum = s[l[0] + 1]
n = gets.chomp.to_i
n.times do
  a, b = gets.chomp.split(' ').map &:to_i
  if a > b
    t = a; a = b; b = t
  end
  puts min(s[b] - s[a], sum - s[b] + s[a])
end
