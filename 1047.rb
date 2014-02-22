# TLE
n, m = gets.chomp.split(' ').map &:to_i
rec = Array.new(m + 1) { Array.new }
n.times do
  input = gets.chomp.split(' ')
  name = input.shift; input.shift
  input.each { |x| rec[x.to_i] << name }
end
1.upto(m) do |i|
  puts "#{i} #{rec[i].size}"
  if rec[i].size != 0
    rec[i].sort!
    rec[i].each { |x| puts x }
  end
end
