a = gets.chomp.split(" ")
b = gets.chomp.split(" ")
c = Array.new(2005) { 0.0 }
1.upto(a[0].to_i) { |i|
    1.upto(b[0].to_i) { |j|
        c[a[i * 2 - 1].to_i + b[j * 2 - 1].to_i] += a[i * 2].to_f * b[j * 2].to_f;
    }
}
print 2005 - c.count(0.0)
2000.downto(0) { |i|
    printf " %d %.1f", i, c[i] if c[i] != 0.0
}
puts

