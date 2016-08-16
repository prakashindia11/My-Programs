#!/user/bin/perl

open(fp,"data.txt");
while($_=<fp>)
{
	$noline++;
	$nochar+=length($_);
	$noword+=split(/\s+/,$_);
}

print("Number of line=$noline\n");
print("Number of char=$nochar\n");
print("Number of word=$noword\n");

