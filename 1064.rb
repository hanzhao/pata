def dfs(r)
  dfs($l[r]) if $l[r]
  $key[r] = $a[$tot]; $tot += 1
  dfs($r[r]) if $r[r]
end
n = gets.chomp.to_i
$a = gets.chomp.split.map &:to_i
$a.sort!
$l = []; $r = []; $key = []; ans = []
sum = 0; d = [[0]]; now = 0; $tot = 0
while sum < n - 1
  d[now + 1] = Array.new
  d[now].each do |x|
    sum += 1; $l[x] = sum; d[now + 1] << sum
    break if sum == n - 1
    sum += 1; $r[x] = sum; d[now + 1] << sum
    break if sum == n - 1
  end
  now += 1
end
dfs(0)
d.each do |i|
  i.each { |j| ans << $key[j] }
end
puts ans.join(' ')

