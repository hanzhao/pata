# TLE
def min(a,b)
  a < b ? a : b
end
exist = []
ans = 1000
n, m = gets.chomp.split(' ').map &:to_i
a = gets.chomp.split(' ').reverse.map &:to_i
a.each do |x|
  ans = min(x,m - x) if x < m && m - x < 500 && exist[m - x] && (x < ans || m - x < ans)
  exist[x] = true
end
if ans < 1000
  puts "#{ans} #{m - ans}"
else
  puts 'No Solution'
end
