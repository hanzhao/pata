# Trick: Dont have to finish all works before 17:00, meet them is ok
n, m, k, q = gets.chomp.split(" ")
n = n.to_i; m = m.to_i; k = k.to_i
ans = Array.new(k) { nil }
nowhour = 8; nowmin = 0
line = Array.new(n) { Array.new }
req = gets.chomp.split(" ")
req.collect! { |x| x.to_i }
tail = 0
m.times { |i|
    n.times { |j|
        break if tail == k
        line[j] << tail
        tail += 1
    }
}
nextone = tail
waiting = tail
while waiting > 0 do
    min = 2147483647
    sel = -1
    line.each_index { |i|
        if !line[i].empty? && min > req[line[i].first]
            min = req[line[i].first]
            sel = i
        end
    }
    line.each_index { |i| req[line[i].first] -= min if !line[i].empty? }
    nowmin += min; nowhour += nowmin / 60; nowmin %= 60
    if nowhour * 60 + nowmin >= 17 * 60
        waiting = 0
        line.each_index { |i|
            if !line[i].empty?
                t = line[i].shift
                line[i].clear
                line[i] << t
                waiting += 1
            end
        }
    end
    id = line[sel].shift
    ans[id] = sprintf("%02d:%02d", nowhour, nowmin)
    if nextone < k && nowhour * 60 + nowmin < 17 * 60
        line[sel] << nextone
        nextone += 1
    else
        waiting -= 1
    end
end
gets.chomp.split(" ").each { |x|
    x = x.to_i - 1
    if (!ans[x])
        puts "Sorry"
    else
        puts ans[x]
    end
}

