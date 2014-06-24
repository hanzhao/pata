#!/usr/bin/env ruby
class Student
  attr_accessor :name, :id, :grade
  def initialize(a)
	@name, @id, @grade = a
	@grade = @grade.to_i
  end
end
n = gets.to_i
all = []
n.times { all << Student.new(gets.split) }
all.sort_by! { |x| x.grade }
flag = false
l, r = gets.split.map &:to_i
all.reverse.each do |x|
  if x.grade >= l && x.grade <= r
	puts "#{x.name} #{x.id}"
	flag = true
  end
end
puts 'NONE' unless flag
