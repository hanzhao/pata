n, m = gets.chomp.split(" ")
n = n.to_i; m = m.to_i
depth = []; queue = []
child = Array.new(105) { Array.new }
ans = []
m.times do
    input = gets.chomp.split(" ")
    r = input[0].to_i
    input[1].to_i.times { |x| child[r] << input[2 + x].to_i }
end
depth[1] = 0
queue << 1
while !queue.empty? do
    now = queue.shift
    ans[depth[now]] = 0 if !ans[depth[now]]
    if child[now].empty?
        ans[depth[now]] += 1
    else child[now].each { |x|
        depth[x] = depth[now] + 1
        queue << x
    }
    end
end
puts ans.join(" ")

