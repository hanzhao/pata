op = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
day = hour = minute = nil
a = gets.chomp; b = gets.chomp; c = gets.chomp; d = gets.chomp
0.upto(a.length < b.length ? a.length - 1 : b.length - 1) { |i|
	if a[i] == b[i]
		if day == nil
			if a[i] >= 'A' && a[i] <= 'G'
				day = a[i]
			end
		elsif hour == nil
			if (a[i] >= '0' && a[i] <= '9') || (a[i] >= 'A' && a[i] <= 'N')
				hour = a[i]
			end
		end
	end
}
0.upto(c.length < d.length ? c.length - 1 : d.length - 1) { |i|
	minute = i if c[i] == d[i] && ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z'))
}
print op[day.ord - 'A'.ord], " "
if hour >= 'A' && hour <= 'N'
	hour = hour.ord - 'A'.ord + 10
else
	hour = hour.to_i
end
printf("%02d:%02d\n",hour,minute)
