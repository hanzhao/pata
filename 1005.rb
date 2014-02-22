op = [ "zero", "one", "two", "three", "four", \
       "five", "six", "seven", "eight", "nine" ]
ans = []; s = 0
num = gets.chomp;
num.each_char { |i| s += num[i].to_i }
s.to_s.each_char { |x| ans << op[x.to_i] }
puts ans.join ' '

