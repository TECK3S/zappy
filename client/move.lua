-- function getWayToCAse
-- parametres:
--case: indice
function	getWayToCAse(case)
   local way = {}
   local w = 0
   local i = 1
   local niv = 0
   while i ~= case do
      if i < case and (i + n) < case then
	 i = n * 2 + i
	 n = n + 1
	 w = w + 1
	 way[w] = avance
      else
	 if i < case and (i + n) >= case then
	    way[w] = droite
	    while i < case do
	       i = i + 1
	       w = w + 1
	       way[w] = avance
	    end
	 else
	    if i > case and (i - n) >= case then
	       way[w] = gauche
	       while i > case do
		  i = i - 1
		  w = w + 1
		  way[w] = avance
	       end
	    end
	 end
      end
   end
   return way
end

function	goToCase(way)
   local i = 1
   while way[i] do
      doAction(way[i])
      catchResonse(way[i])
      i = i + 1
   end
   return true
end