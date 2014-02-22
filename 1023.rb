n = gets.chomp.to_i; n2 = n * 2
an = n.to_s.split(//).sort; an2 = n2.to_s.split(//).sort
puts an == an2 ? "Yes" : "No", n2

