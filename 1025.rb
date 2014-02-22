# TLE
class Testee
    attr_accessor :sid, :score, :local
    def initialize(sid, score, local)
        @sid = sid; @score = score; @local = local
    end
end
n = gets.chomp.to_i
local = Array.new(n) { Array.new }
all = []
lrank = {}
n.times { |i|
    m = gets.chomp.to_i
    m.times do
        sid, score = gets.chomp.split(" ")
        score = score.to_i
        all << Testee.new(sid, score, i + 1)
        local[i] << Testee.new(sid, score, i + 1)
    end
}
local.each_index { |i|
    local[i].sort! { |a, b| b.score <=> a.score }
    last = -1000; lastid = nil
    local[i].each_with_index { |j, index|
        lrank[j.sid] = (j.score == last ? lrank[lastid] : index + 1) 
        last = j.score; lastid = j.sid
    }
}
all.sort! { |a,b| a.score == b.score ? a.sid <=> b.sid : b.score <=> a.score }
puts all.length
last = -1000; lastrank = 0
all.each_index { |i|
    x = all[i]
    print x.sid , " "
    print t = (x.score == last ? lastrank : i + 1) , " "
    print x.local, " "
    print lrank[x.sid], "\n"
    last = x.score; lastrank = t
}

