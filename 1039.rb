# TLE
hash = {}
n, m = gets.chomp.split(' ').map &:to_i
m.times do
  id, s = gets.chomp.split(' ').map &:to_i
  names = gets.chomp.split(' ')
  names.each do |x|
    hash[x] = Array.new if !hash[x]
    hash[x] << id
  end
end
names = gets.chomp.split(' ')
names.each do |x|
  if !hash[x]
    puts "#{x} 0"
  else
    puts "#{x} #{hash[x].size} #{hash[x].sort.join(' ')}"
  end
end
