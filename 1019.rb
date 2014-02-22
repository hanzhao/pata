def trans(n, radix)
    if n == 0
        return [ 0 ]
    end
    res = []
    while n > 0
        res << n % radix
        n /= radix
    end
    return res.reverse
end
n, r = gets.chomp.split(" ").collect &:to_i
express = trans(n, r)
puts express.reverse == express ? "Yes" : "No"
puts express.join(" ")

