require 'bigdecimal'
g = []; op = [ "W", "T", "L" ]
ans = BigDecimal.new("1.0")
3.times { |i| g[i] = gets.chomp.split(" ") }
3.times { |i|
    max = -1.0
    choose = -1
    3.times { |j|
        if g[i][j].to_f > max
            max = g[i][j].to_f
            choose = j
        end
    }
    ans *= max
    print op[choose] , " "
}
printf "%.2f\n", 2.0 * (ans * 0.65 - 1.0)

