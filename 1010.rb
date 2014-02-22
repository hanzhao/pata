$map = Array.new(305)
def trans(s, radix)
    res = 0
    s.each_char { |x|
        if !$map[x.ord] || $map[x.ord] >= radix
            return -1
        end
        res *= radix
        res += $map[x.ord]
    }
    return res
end
a, b, tag, radix = gets.chomp.split(" ")
(t = a; a = b; b = t) if tag == "2"
flag = false
"0".ord.upto("9".ord) { |x| $map[x] = x - "0".ord }
"a".ord.upto("z".ord) { |x| $map[x] = x - "a".ord + 10 }
an = trans(a, radix.to_i)
bn = 0
l = 0; r = 21474836470
while l < r do
    mid = (l + r) / 2
    bn = trans(b, mid)
    r = mid if bn >= an
    l = mid + 1 if bn < an
end
(puts r; flag = true) if trans(b, r) == an    
puts "Impossible" if !flag

