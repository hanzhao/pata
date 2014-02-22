class Person
    attr_accessor :id, :signin, :signout
    def initialize(a)
        @id = a[0]
        @signin = a[1]
        @signout = a[2]
    end
end
n = gets.chomp.to_i
r = []
n.times { r << Person.new(gets.chomp.split(" ")) }
r.sort_by! { |x| x.signin }
print r.first.id, " "
r.sort_by! { |x| x.signout }
print r.last.id, "\n"

