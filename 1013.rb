# You will get TLE with ruby in this problem
n, m, k = gets.chomp.split(" ")
n = n.to_i; m = m.to_i; k = k.to_i
edge = Array.new(n) { Array.new }
m.times do
    s, t = gets.chomp.split(" ")
    s = s.to_i - 1; t = t.to_i - 1
    edge[s] << t
    edge[t] << s
end
gets.chomp.split(" ").each { |x|
    x = x.to_i - 1
    ans = 0
    queue = []
    color = Array.new(n) { nil }
    0.upto(n - 1) { |i|
        if !color[i] && i != x
            color[i] = (ans += 1)
            queue << i
            while !queue.empty? do
                edge[queue.shift].each { |t|
                    if !color[t] && t != x
                        color[t] = ans
                        queue << t
                    end
                }
            end
        end
    }
    puts ans - 1
}

