n = gets.to_i
all = []
ans = ""
n.times do
	all << gets.chomp.reverse
end
0.upto(all[0].size - 1) do |i|
	flag = false
	1.upto(all.size - 1) do |j|
		if all[j][i] != all[0][i]
			flag = true
			break
		end
	end
	break if flag
	ans += all[0][i]
end
if ans == ""
	puts 'nai'
else
	puts ans.reverse
end
