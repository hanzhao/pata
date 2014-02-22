def trans(x, radix)
    if x == 0
        return "0"
    end
    res = ""
    while x > 0
        t = x % radix
        res += t.to_s
        x /= radix
    end
    return res
end
noprime = [ true, true ]; prime = []
2.upto(100005) { |i|
    if !noprime[i]
        prime << i
    end
    prime.each { |x|
        if x * i < 100000
            noprime[x * i] = true
            break if i % x == 0
        else
            break
        end
    }
}
while true do
    input = gets.chomp.split(" ")
    break if input.length != 2
    radix = input[1].to_i
    a = input[0].to_i
    b = trans(a, radix).to_i(radix)
    if !noprime[a] && !noprime[b]
        puts "Yes"
    else
        puts "No"
    end
end

