x = gets.chomp.split(" ")
now = 0; ans = 0
for i in 1..x[0].to_i do
    ans += (now - x[i].to_i) * 4 + 5 if now > x[i].to_i
    ans += (x[i].to_i - now) * 6 + 5 if now < x[i].to_i
    ans += 5 if now == x[i].to_i
    now = x[i].to_i
end
puts ans

