n = gets.chomp.to_i
ans = 0
as = []; apw = []
n.times do
	s, pw = gets.split(' ')
	pw2 = pw.gsub('1','@').gsub('0','%').gsub('l','L').gsub('O','o')
	if pw != pw2
		ans += 1
		as << s; apw << pw2
	end
end
if ans == 0
	puts "There is #{n} account and no account is modified" if n == 1
	puts "There are #{n} accounts and no account is modified" if n != 1
else
	puts ans
	ans.times { |i| puts "#{as[i]} #{apw[i]}" }
end

