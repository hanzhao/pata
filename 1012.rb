# You will get TLE with ruby in this problem. :)
class Student
    attr_accessor :id
    attr_accessor :s
    def initialize(a)
        @id = a[0]
        @s = [ a[1].to_i + a[2].to_i + a[3].to_i, a[1].to_i, a[2].to_i, a[3].to_i ]
    end
end
op = [ "A", "C", "M", "E" ]
n, m = gets.chomp.split(" ")
n = n.to_i; m = m.to_i
all = []
n.times { all << Student.new(gets.chomp.split(" ")) }
m.times do
    now = gets.chomp
    find = false
    s = []
    all.each { |x|
        if x.id == now
            find = true
            s = x.s
            break
        end
    }
    if !find
        puts "N/A"
        next
    end
    rank = [ 1, 1, 1, 1 ]
    all.each { |x|
        4.times { |i| rank[i] += 1 if x.s[i] > s[i] }
    }
    res = 2005; sel = nil
    4.times { |i|
        if rank[i] < res
            res = rank[i]
            sel = op[i]
        end
    }
    print res, " ", sel, "\n"
end

