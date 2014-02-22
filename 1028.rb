n, c = gets.chomp.split(" ").collect &:to_i
all = []
n.times { all << gets.chomp.split(" ") }
all.sort! { |a, b| a[c - 1] == b[c - 1] ? a[0] <=> b[0] : a[c - 1] <=> b[c - 1] }
all.each { |x| puts x.join(" ") }

