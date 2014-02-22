class Student
	attr_accessor :name, :id, :grade
	def initialize(name, id, grade)
		@name = name; @id = id; @grade = grade
	end
	def to_s
		"#{@name} #{@id}"
	end
end
n = gets.chomp.to_i
m = []; f = []
n.times do
	name, sex, id, grade = gets.chomp.split(' ')
	grade = grade.to_i
	m << Student.new(name, id, grade) if sex == 'M'
	f << Student.new(name, id, grade) if sex == 'F'
end
m.sort_by!{ |x| x.grade }; f.sort_by!{ |x| x.grade }
if f.empty?
	puts 'Absent'
else
	puts f.last
end
if m.empty?
	puts 'Absent'
else
	puts m.first
end
if f.empty? || m.empty?
	puts 'NA'
else
	puts f.last.grade - m.first.grade
end

