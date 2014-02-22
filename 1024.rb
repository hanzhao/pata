n, k = gets.chomp.split(" ").collect &:to_i
now = n
(k + 1).times { |i|
    rev = now.to_s.reverse.to_i
    if now == rev
        puts now, i
        break
    end
    if i == k
        puts now, i
        break
    end
    now += rev
}

