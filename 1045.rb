$b = []; $ans = 0
def find(x)
  l = 1; r = $ans
  while l <= r
    mid = l + r >> 1
    if $b[mid] <= x
      l = mid + 1
    else
      r = mid - 1
    end
  end
  l
end
index = []
n = gets.chomp.to_i
like = gets.chomp.split; like.shift
like.each_with_index { |x, i| index[x.to_i] = i + 1 }
all = gets.chomp.split.map { |x| index[x.to_i] }; all.shift; all.compact!
all.each do |x|
  t = find(x)
  $ans = t if $ans < t
  $b[t] = x
end
puts $ans

