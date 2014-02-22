class Edge
  attr_accessor :tr, :len
  def initialize(t, l)
    @tr = t; @len = l
  end
end
class AnsClass
  attr_accessor :path, :send, :back
  def initialize(path, send, back)
    @path = Array.new(path)
    @send = send; @back = back
  end
end
def dfs(s, send, carry)
  $path << s
  if carry + $c[s] < 0
    send += carry + $c[s]; carry = 0
  else
    carry += $c[s]
  end
  if s == $t
    $ans << AnsClass.new($path, -send, carry)
  else
    $edge[s].each { |x| dfs(x.tr, send, carry) if $dist[s] + x.len == $dist[x.tr] }
  end
  $path.pop
end
cmax, n, $t, m = gets.chomp.split.map &:to_i
half = cmax >> 1
$ans = []
$path = []
$edge = Array.new(n + 1) { Array.new }
$c = gets.chomp.split.map { |x| x.to_i - half }
$c.unshift(0)
m.times do
  a, b, d = gets.chomp.split.map &:to_i
  $edge[a] << Edge.new(b, d)
  $edge[b] << Edge.new(a, d)
end
$dist = [0]
q = [0]; inq = []; inq[0] = true
while !q.empty? do
  s = q.shift
  $edge[s].each do |x|
    if !$dist[x.tr] || $dist[x.tr] > $dist[s] + x.len
      $dist[x.tr] = $dist[s] + x.len
      if !inq[x.tr]
        q << x.tr
        inq[x.tr] = true
      end
    end
  end
  inq[s] = false
end
dfs(0,0,0)
$ans.sort! { |a, b| a.send == b.send ? (a.back <=> b.back) : (a.send <=> b.send) }
puts "#{$ans.first.send} #{$ans.first.path.join('->')} #{$ans.first.back}"

