class Num
  attr_accessor :num, :id
  def initialize(a, b)
    @num = a; @id = b
  end
end
def max(a, b)
  if a == nil
    b
  else
    a.num > b.num ? a : b
  end
end
n, m = gets.chomp.split(' ').map &:to_i
input = gets.chomp.split(' ').map &:to_i
w = []; w[0] = Array.new
rank = []
gets.chomp.split(' ').each_with_index { |x, i| w[0][i] = Num.new(input[x.to_i], x.to_i) }
now = 0
while w[now].size != 1
  w[now + 1] = Array.new
  w[now].each_with_index { |x, i| w[now + 1][i / m] = max(w[now + 1][i / m], w[now][i]) }
  now += 1
end
ranked = 0
now.downto(0) do |i|
  nowrank = ranked + 1
  w[i].each do |x|
    if !rank[x.id]
      rank[x.id] = nowrank
      ranked += 1
    end
  end
end
puts rank.join(' ')
