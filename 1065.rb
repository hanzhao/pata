n = gets.chomp.to_i
n.times { |i|
	a, b, c = gets.chomp.split(" ")
	a = a.to_i; b = b.to_i; c = c.to_i
	print "Case ##{i + 1}: ", a + b > c ? "true" : "false", "\n"
}
