# TLE
n = gets.chomp.to_i
edge = Array.new(n) { Array.new }
(n - 1).times do
    a, b = gets.chomp.split(" ").collect { |x| x.to_i - 1 }
    edge[a] << b
    edge[b] << a
end
color = []; dep = Array.new(n)
q = []
csum = 0; long = 0
0.upto(n - 1) { |x|
    if !color[x]
        csum += 1
        color[x] = csum
        dep[x] = 0
        q << x
        while !q.empty? do
            t = q.shift
            edge[t].each { |tr|
                if !color[tr]
                    color[tr] = csum
                    dep[tr] = dep[t] + 1
                    long = long > dep[tr] ? long : dep[tr]
                    q << tr
                end
            }
        end
    end
}
if csum != 1
    puts "Error: #{csum} components"
    exit
end
ans = []
dep.each_with_index { |x,i|
    if x == long
        longest = 0
        ans << i
        q.clear; q << i
        newdep = Array.new(n); newdep[i] = 0
        while !q.empty? do
            t = q.shift
            edge[t].each { |tr|
                if !newdep[tr]
                    newdep[tr] = newdep[t] + 1
                    longest = longest > newdep[tr] ? longest : newdep[tr]
                    q << tr
                end
            }
        end
        newdep.each_index { |new| ans << new if newdep[new] == longest}
    end
}
puts ans.uniq.sort.collect { |x| x + 1 }.join("\n")

