# encodeIndels.sql was originally generated by the autoSql program, which also 
# generated encodeIndels.c and encodeIndels.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#ENCODE Deletion and Insertion Polymorphisms from NHGRI
CREATE TABLE encodeIndels (
    bin smallint not null,
    chrom varchar(255) not null,	# Chromosome
    chromStart int unsigned not null,	# Start position in chromosome
    chromEnd int unsigned not null,	# End position in chromosome
    name varchar(255) not null,	# Trace sequence
    score int unsigned not null,	# Quality score 
    strand char(1) not null,	# Always +
    thickStart int unsigned not null,	# Start position in chromosome
    thickEnd int unsigned not null,	# End position in chromosome
    reserved int unsigned not null,	# Reserved
    traceName varchar(255) not null,	# Name of trace
    traceId varchar(255) not null,	# Trace Id (always integer)
    tracePos int unsigned not null,	# Position in trace
    traceStrand char(1) not null,	# Value should be + or -
    variant varchar(255) not null,	# Variant sequence
    reference varchar(255) not null,	# Reference sequence
    #Indices
    INDEX chrom (chrom(12),chromStart),
    INDEX name (name)
);
