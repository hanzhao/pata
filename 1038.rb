a = gets.chomp.split
a.shift
a.sort! { |a, b| a + b <=> b + a }
while true do
  a[0] = a[0].to_i
  break if a[0] != 0 || a.size == 1
  a.shift
end
puts a.join

