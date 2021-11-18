	.text	
	.globl	f
f:
	addiu	$29, $29, -12
	sw	$30, 8($29)
	move	$30, $29
	sw	$4, 12($30)
	sw	$5, 16($30)
	sw	$2, 4($30)
	lw	$2, 12($30)
	sw	$2, 0($30)
	lw	$3, 16($30)
	lw	$2, 0($30)
	or	$2, $2, $3
	sw	$2, 4($30)
	lw	$2, 4($30)
	b	$L1
	nop
$L1:
	move	$29, $30
	lw	$30, 8($29)
	addiu	$29, $29, 12
	jr	$31
	nop
# --- END FUNCTION DEFINITION ---
