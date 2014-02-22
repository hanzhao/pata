n = gets.chomp.to_i
nums = gets.chomp.split(" ")
s = 0; now = 0; ans = 0; anss = nums.first; anst = nums.last
zero = false
nums.each_index { |i|
    x = nums[i].to_i
    zero = true if x == 0
    if now + x > 0
        s = x if now == 0
        now += x
        if ans < now
            ans = now; anss = s; anst = x
        end
    else
        now = 0
    end
}
print ans, " "
if ans == 0 && zero
    print "0 0\n"
else
    print anss, " ", anst, "\n"
end

