n = gets.chomp.to_i
n = sprintf "%04d", n
fir = true
while (n != "6174" && n != "0000") || fir do
	fir = false
	b = n.split(//).sort
	a = b.reverse
	a = a.join.to_i; b = b.join.to_i
	printf "%04d - %04d = %04d\n", a, b, a - b
	n = sprintf "%04d", a - b
end
