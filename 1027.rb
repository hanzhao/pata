def trans(n)
    op = "0123456789ABC"
    if n == 0
        return "00"
    end
    res = ""
    while n > 0
        res += op[n % 13]
        n /= 13
    end
    res += "0" if res.length == 1
    return res.reverse
end
a, b, c = gets.chomp.split(" ").collect &:to_i
puts "##{trans(a)}#{trans(b)}#{trans(c)}"

