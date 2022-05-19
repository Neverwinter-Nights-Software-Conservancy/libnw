<?xml version="1.0" encoding="US-ASCII"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <xsl:for-each select="GIT">
    <html>
      <body>
        <h1>BioWare GIT Contents</h1>
	    <xsl:for-each select="OBJECT">
	      <h2><xsl:value-of select="@NAME"/></h2>
          <table border="1">
            <tr>
              <th colspan="2"><xsl:value-of select="@NAME"/></th>
            </tr>
            <tr>
              <th align="left">Property</th>
              <th align="left">Value</th>
            </tr>
			<xsl:for-each select="RECORD">
			  <xsl:for-each select="OBJECT">
			    <tr>
				  <td><xsl:value-of select="name()"/></td>
				  <td><xsl:value-of select="@NAME"/></td>
				</tr>
			  </xsl:for-each>
			</xsl:for-each>
		  </table>
	    </xsl:for-each>
      </body>
    </html>
  </xsl:for-each>
</xsl:template>

</xsl:stylesheet>
