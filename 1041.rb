times = Array.new(10005)
a = gets.chomp.split(' ').map &:to_i
a.shift
a.each do |x|
  if times[x] == nil
    times[x] = 1;
  else
    times[x] += 1
  end
end
a.each do |x|
  if times[x] == 1
    puts x
    exit
  end
end
puts 'None'
