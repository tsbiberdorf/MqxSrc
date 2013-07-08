# this tool processes the prepare.txt file and creates a batch program which 
# generates the final codesize reports as specifed

# usage:  prepare.pl > do_all.bat

$DEBUG = 0;
$INFILE = shift;
$INFILE = "prepare.txt" if not $INFILE; 

open MAPFILES, $INFILE or die "Can not open \"$INFILE\" input file";

$inrep = 0;
$nl = $DEBUG ? "\n" : "";

while($line = <MAPFILES>)
{
  chomp $line;
  
  # comment line
  next if $line =~ /^\s*\#/;
  
  # report begins here
  if($line =~ /^\s*report\s+\"(.*)\"/)
  {
    print "..\\codesize.pl -o $1 ";
    #print " -K";  # kernel symbols (not working with uv4)
    print " -W";   # debugging warning messages
    print "$nl";
    $inrep = 1;
    next;
  }
  
  # need to be in report to accept next input lines
  next if not $inrep;
  
  # map file entry, parse board, tool etc.
  if($line =~ /app\\(\w+)\.(\w+)\\(\w+)_(\w+)\\/)
  {
    # new line -> process collected mapfiles
    $board = $1;
    $mapfmt = $2;
    $kernel = $3;
    $cscfg = $4;
    
    print " -c $mapfmt -n \"$board\" -n2 \"$kernel kernel\" -n3 \"$cscfg app\" $line $nl";
  }
  else
  {
    # this report is done 
    print "\n\n";
    $inrep = 0;
  }
}

print "\n";

close MAPFILES;
0;
