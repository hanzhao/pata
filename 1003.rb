def min(a, b)
    a < b ? a : b
end
def max(a, b)
    a > b ? a : b
end
n, m, s, t = gets.chomp.split(" ")
n = n.to_i; m = m.to_i; s = s.to_i; t = t.to_i
inmap = []; times = []; sum = []; dist = Array.new(505, 1000000000)
peo = gets.chomp.split(" ")
map = Array.new(505) { Array.new(505, 1000000005) }
m.times do
    f, r, l = gets.chomp.split(" ")
    f = f.to_i; r = r.to_i; l = l.to_i
    map[f][r] = map[r][f] = min(map[f][r],l)
end
inmap[s] = true; dist[s] = 0; times[s] = 1; sum[s] = peo[s].to_i
last = s
(n - 1).times do
    min = 1000000000
    select = -1
    n.times { |x|
        if !inmap[x]
            if dist[x] > dist[last] + map[last][x]
                dist[x] = dist[last] + map[last][x]
                times[x] = times[last]
                sum[x] = sum[last] + peo[x].to_i
            elsif dist[x] == dist[last] + map[last][x]
                times[x] += times[last]
                sum[x] = max(sum[x], sum[last] + peo[x].to_i)
            end
            if min > dist[x]
                min = dist[x]; select = x;
            end
       end
    }
    break if select == -1
    inmap[select] = true; last = select
end
print times[t], " ", sum[t], "\n"

