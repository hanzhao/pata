c = [0]; nc = [0]
1.upto(13) do |i|
  c[i] = 'S' + i.to_s
  c[i + 13] = 'H' + i.to_s
  c[i + 26] = 'C' + i.to_s
  c[i + 39] = 'D' + i.to_s
end
c[53] = 'J1'; c[54] = 'J2'
n = gets.chomp.to_i
p = gets.chomp.split(' ').map &:to_i
p.unshift(0)
n.times do
  1.upto(54) { |i| nc[p[i]] = c[i] }
  c = nc * 1
end
c.shift
puts c.join(' ')
