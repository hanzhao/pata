c = Array.new(10001)
a = gets.chomp.split(" ")
b = gets.chomp.split(" ")
c.each_index { |i| c[i] = 0.0 }
1.upto(a[0].to_i) { |i| c[a[i * 2 - 1].to_i] += a[i * 2].to_f }
1.upto(b[0].to_i) { |i| c[b[i * 2 - 1].to_i] += b[i * 2].to_f }
print 10001 - c.count(0.0)
10000.downto(0) { |i|
	if c[i] != 0.0
		printf " %d %.1f", i, c[i]
	end
}
puts

