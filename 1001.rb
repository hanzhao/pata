a, b = gets.chomp.split(" ")
a = a.to_i; b = b.to_i
ans = sprintf("%d", a + b).split(//).reverse
(ans.length - 1).downto(0) { |i|
	if ans[i] != "-" && i != 0 && i % 3 == 0
		print ans[i], ','
	else
		printf ans[i]
	end
}
puts

