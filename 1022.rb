hashtle = {}
hashart = {}
hashkey = {}
hashpub = {}
hashyir = {}
n = gets.chomp.to_i
n.times do
    id = gets.chomp; tle = gets.chomp; art = gets.chomp
    keys = gets.chomp.split(" "); pub = gets.chomp; yir = gets.chomp
    hashtle[tle] = Array.new if !hashtle[tle]
    hashtle[tle] << id
    hashart[art] = Array.new if !hashart[art]
    hashart[art] << id
    keys.each { |key|
        hashkey[key] = Array.new if !hashkey[key]
        hashkey[key] << id
    }
    hashpub[pub] = Array.new if !hashpub[pub]
    hashpub[pub] << id
    hashyir[yir] = Array.new if !hashyir[yir]
    hashyir[yir] << id
end
gets.chomp.to_i.times do
    input = gets.chomp
    puts input
    op, str = input.split(": ")
    op = op.to_i
    if op == 1
        if !hashtle[str]
            puts "Not Found"
        else
            puts hashtle[str].sort
        end
    elsif op == 2
        if !hashart[str]
            puts "Not Found"
        else
            puts hashart[str].sort
        end
    elsif op == 3
        if !hashkey[str]
            puts "Not Found"
        else
            puts hashkey[str].sort
        end
    elsif op == 4
        if !hashpub[str]
            puts "Not Found"
        else
            puts hashpub[str].sort
        end
    else
        if !hashyir[str]
            puts "Not Found"
        else
            puts hashyir[str].sort
        end
    end
end

