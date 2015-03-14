
$fxshift = 2
$fxmask = 0x03
$bool_f = 0x2F
$bool_t = 0x6F
$wordsize = 4
$char_tag = 0x0F
$tag_shift = 58
$nil = 0x3F
$fx_int = 0x00
$fixnum_bits = ($wordsize * 8) - $fxshift
$fxlower = -(2**($fixnum_bits - 1))
$fxupper = 2**($fixnum_bits - 1) - 1

def ash_s(n, count)
  return n * (2**count)
end

def get_tag(x)
  return [x].pack("I").unpack("cccc")[0]
end

def num_to_s(x)
  return x << $fxshift
end

def char_to_s(x)
  return (x.ord << 8)|$char_tag
end

def fixnum?(x)
  return (x.is_a? Integer) && ((x & $fxmask) == $fx_int) && 
    ($fxlower <= x) && (x <= $fxupper)
end

def boolean_t?(x)
  return (x == $bool_f || x == $bool_t)
end

def char_t?(x)
  return get_tag(x) == $char_tag
end

def immediate?(x)
  return (boolean_t?(x) || char_t?(x) || fixnum?(x))
end

def immediate_rep(x)
  if (fixnum?(x))
    return x
  elsif (char_t?(x))
    return x
  else
    return x
  end
end

def emmit_program(x)
  "    .text
    .globl scheme_entry
    .type scheme_entry, @function
scheme_entry:
    movl $#{immediate_rep(x)}, %eax
    ret\n"
end

File.write("test.s", emmit_program($bool_t))
#print emmit_program(char_to_s('a'))
#puts char_to_s('A')

