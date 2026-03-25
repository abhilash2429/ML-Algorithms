#include &lt;stdio.h&gt;
#define FRAME_SIZE 1024 // size of each frame/page
int main() {
int pageTable[100], nPages, logicalAddr, pageNumber, offset, physicalAddr;
printf(&quot;Enter number of pages: &quot;);
scanf(&quot;%d&quot;, &amp;nPages);
printf(&quot;Enter the page table (frame number for each page):\n&quot;);
for (int i = 0; i &lt; nPages; i++) {
printf(&quot;Page %d: &quot;, i);
scanf(&quot;%d&quot;, &amp;pageTable[i]);
}
printf(&quot;\nEnter a logical address (0 to %d): &quot;, nPages * FRAME_SIZE - 1);
scanf(&quot;%d&quot;, &amp;logicalAddr);
pageNumber = logicalAddr / FRAME_SIZE;
offset = logicalAddr % FRAME_SIZE;

if (pageNumber &gt;= nPages) {
printf(&quot;Invalid logical address. Page number out of range.\n&quot;);
} else {
physicalAddr = pageTable[pageNumber] * FRAME_SIZE + offset;
printf(&quot;Physical Address: %d\n&quot;, physicalAddr);
}
return 0;
}
