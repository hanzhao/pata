class Cake
	attr_accessor :price
	attr_accessor :num
	def initialize(price, num)
		@price = price
		@num = num
	end
end
n, m = gets.chomp.split(" ")
n = n.to_i; m = m.to_f
nums = gets.chomp.split(" ")
tcost = gets.chomp.split(" ")
list = []
get = 0.0
n.times { |i| list << Cake.new(tcost[i].to_f / nums[i].to_f, nums[i].to_f) }
list.sort! { |a,b| a.price <=> b.price }
list.reverse!
list.each { |x|
	use = x.num > m ? m : x.num
	get += use * x.price
	m -= use
	if m <= 1e-7
		break;
	end
}
printf("%.2f\n", get)
