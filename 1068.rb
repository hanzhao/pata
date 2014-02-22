n, m = gets.chomp.split.map &:to_i
a = gets.chomp.split.map { |x| x.to_i > m ? nil : x.to_i }.compact.sort { |a,b| b <=> a }
f = [[0]]; c = [[0]]
a.each_with_index do |x, i|
  f[i] = Array.new(f[i - 1]) if i > 0
  c[i] = Array.new(c[i - 1]) if i > 0
  if x <= m
    m.downto(x) do |j|
      if f[i][j - x]
        f[i][j] = x
        c[i][j] = i
      end
    end
  end
end
if a.size > 0 && f[a.size - 1][m]
  ans = []
  now = a.size - 1
  while m != 0
    ans << f[now][m]
    tmp = m
    m -= f[now][m]
    now = c[now][tmp] - 1
  end
  puts ans.join(' ')
else
  puts 'No Solution'
end

